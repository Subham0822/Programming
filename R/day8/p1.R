# Install and load the necessary libraries
install.packages("caret")
library(caret)
install.packages("C50")
library(C50)
install.packages("readxl")  # Install the readxl package
library(readxl)  # Load the readxl package

# Read the Excel file using readxl
d <- read_excel("C://Users//RWIK//Downloads//RidingMowers larger dataset.xls")

# Print column names
print(colnames(d))

# Define input variables and target variable
vars <- colnames(d)[1:(ncol(d) - 1)]
target_var <- colnames(d)[ncol(d)]

# Check if the target variable exists in the dataset
if (!target_var %in% colnames(d)) {
  stop(paste("Target variable", target_var, "not found in the dataset."))
}

# Subset the dataset to include only relevant columns
cc <- d[, c(vars, target_var)]

# Function to evaluate the model
evaluate_model <- function(train_data, test_data, vars, target_var) {
  tree_mod <- C5.0(x = train_data[, vars], y = factor(train_data[[target_var]]))
  plot(tree_mod)
  predict_train <- predict(tree_mod, newdata = train_data, type = "class")
  strain <- table(train_data[[target_var]], predict_train, dnn = c("Actual", "Predicted"))
  
  predict_test <- predict(tree_mod, newdata = test_data, type = "class")
  stest <- table(test_data[[target_var]], predict_test, dnn = c("Actual", "Predicted"))
  
  accuracy_train <- sum(diag(strain)) / sum(strain)
  sensitivity_train <- strain[2, 2] / sum(strain[2, ])
  specificity_train <- strain[1, 1] / sum(strain[1, ])
  
  accuracy_test <- sum(diag(stest)) / sum(stest)
  sensitivity_test <- stest[2, 2] / sum(stest[2, ])
  specificity_test <- stest[1, 1] / sum(stest[1, ])
  
  list(
    train = data.frame(Accuracy = accuracy_train, Sensitivity = sensitivity_train, Specificity = specificity_train),
    test = data.frame(Accuracy = accuracy_test, Sensitivity = sensitivity_test, Specificity = specificity_test)
  )
}

# Define partition percentages
partitions <- c(0.4, 0.5, 0.6, 0.7, 0.8)

# Lists to store results
train_results <- list()
test_results <- list()

# Loop through partitions to evaluate the model
for (p in partitions) {
  sz <- nrow(cc) * p
  set.seed(1234)
  in_train <- sample(1:nrow(cc), size = sz)
  train_data <- cc[in_train, ]
  test_data <- cc[-in_train, ]
  
  res <- evaluate_model(train_data, test_data, vars, target_var)
  
  train_results[[paste0(p * 100, "%")]] <- res$train
  test_results[[paste0(p * 100, "%")]] <- res$test
}

# Combine results into data frames
train_results_df <- do.call(rbind, train_results)
test_results_df <- do.call(rbind, test_results)

# Add partition labels to the data frames
train_results_df$Partition <- rownames(train_results_df)
test_results_df$Partition <- rownames(test_results_df)

# Display training set results
cat("Training Set Results:\n")
print(train_results_df)

# Display test set results
cat("\nTest Set Results:\n")
print(test_results_df)