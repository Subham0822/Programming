dict1={1:"Ankit",2:"Rohan",3:"Arpan"}
print(dict1[2])
#print(dict1[4])
del dict1[3]
print(dict1.clear())
print(dict1.get(3,"Element not found"))
keys=["Ankit","Ritam","Debjit"]
values=["Python","C","Java"]
data=dict(zip(keys,values))
print(data)
print(data["Ankit"])
data["Subham"]="React"
print(data)
datas={"C":"DevC","Python":["Anaconda","Pycharm"],"Java":{"1":"Netbeans",2:"Eclipse"}}
print(datas["Python"][0])

print(type(dict1))

thisdict=dict(name="john",age=36,country="Norway")
print(thisdict)
