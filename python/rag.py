import faiss
import google.generativeai as genai
import numpy as np
from sentence_transformers import SentenceTransformer

# Initialize Generative AI
API_KEY = ""
genai.configure(api_key=API_KEY)

# Load Sentence Transformer Model
embed_model = SentenceTransformer("all-MiniLM-L6-v2")

# Read and Embed Data
def create_vector_store(file_path):
    with open(file_path, "r", encoding="utf-8") as f:
        lines = f.readlines()
    
    documents = ["".join(lines[i:i+1]) for i in range(0, len(lines), 1)]
    
    embeddings = np.array([embed_model.encode(doc) for doc in documents]).astype('float32')
    
    index = faiss.IndexFlatL2(embeddings.shape[1])
    index.add(embeddings)
    return index, documents

# Search Function
def retrieve(query, index, documents, top_k=2):
    query_vec = np.array([embed_model.encode(query)]).astype('float32')
    _, indices = index.search(query_vec, top_k)
    return [documents[i] for i in indices[0]]

# Generate Response
def generate_response(query, index, documents):
    relevant_texts = retrieve(query, index, documents)
    context = "\n".join(relevant_texts)
    print("comtext:", context)
    
    model = genai.GenerativeModel("gemini-2.0-flash")
    prompt = f"Using only the following context, provide a descriptive and accurate answer to the query.\n\nContext:\n{context}\n\nQuery:\n{query}"
    print("Prompt:", prompt)
    response = model.generate_content(prompt)
    return response.text

# Usage
if __name__ == "__main__":
    index, documents = create_vector_store("data.txt")
    query = "Where is chingrighata?"
    response = generate_response(query, index, documents)
    print("Response:", response)