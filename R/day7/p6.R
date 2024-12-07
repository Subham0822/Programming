# Required libraries
install.packages("caret")
library(caret)
install.packages("C50")
library(C50)

# Load dataset
d <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/ClassificationSimplecases.csv")

# Variables for the model
vars <- c(colnames(d)[2:5])
cc <- d[, c(vars, "buys")]

# Function to evaluate the model
evaluate_model <- function(train_data, test_data, vars) {
  # Build the C5.0 model
  tree_mod <- C5.0(x = train_data[, vars], y = factor(train_data$buys))
  
  # Plot the decision tree
  plot(tree_mod)  # Plotting the decision tree for each partition
  
  # Predictions for training data
  predict_train <- predict(tree_mod, newdata = train_data, type = "class")
  strain <- table(train_data$buys, predict_train, dnn = c("Actual", "Predicted"))
  
  # Predictions for test data
  predict_test <- predict(tree_mod, newdata = test_data, type = "class")
  stest <- table(test_data$buys, predict_test, dnn = c("Actual", "Predicted"))
  
  # Accuracy, sensitivity, specificity for training data
  accuracy_train <- sum(diag(strain)) / sum(strain)
  sensitivity_train <- strain[2, 2] / sum(strain[2, ])
  specificity_train <- strain[1, 1] / sum(strain[1, ])
  
  # Accuracy, sensitivity, specificity for test data
  accuracy_test <- sum(diag(stest)) / sum(stest)
  sensitivity_test <- stest[2, 2] / sum(stest[2, ])
  specificity_test <- stest[1, 1] / sum(stest[1, ])
  
  # Return results for both training and test sets
  list(
    train = data.frame(Accuracy = accuracy_train, Sensitivity = sensitivity_train, Specificity = specificity_train),
    test = data.frame(Accuracy = accuracy_test, Sensitivity = sensitivity_test, Specificity = specificity_test)
  )
}

# Partition sizes to evaluate
partitions <- c(0.4, 0.5, 0.6, 0.7, 0.8)

train_results <- list()
test_results <- list()

# Loop through each partition size
for (p in partitions) {
  sz <- nrow(cc) * p
  set.seed(1234)
  in_train <- sample(1:nrow(cc), size = sz)
  train_data <- cc[in_train, ]
  test_data <- cc[-in_train, ]
  
  # Evaluate the model for the current partition
  res <- evaluate_model(train_data, test_data, vars)
  
  # Store results for both training and test sets
  train_results[[paste0(p * 100, "%")]] <- res$train
  test_results[[paste0(p * 100, "%")]] <- res$test
}

# Combine results into data frames
train_results_df <- do.call(rbind, train_results)
test_results_df <- do.call(rbind, test_results)

# Add partition size as a column for easier interpretation
train_results_df$Partition <- rownames(train_results_df)
test_results_df$Partition <- rownames(test_results_df)

# Print the results
cat("Training Set Results:\n")
print(train_results_df)
cat("\nTest Set Results:\n")
print(test_results_df)

# Plotting one final decision tree from the last partition size (for example, 80%)
# You can modify this part to plot the tree for any specific partition size.
tree_mod_final <- C5.0(x = train_data[, vars], y = factor(train_data$buys))
plot(tree_mod_final)