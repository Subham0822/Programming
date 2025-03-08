# Install and load necessary libraries
#install.packages("caret")
#install.packages("C50")
#install.packages("e1071")
#install.packages("readxl")  # Install the readxl package

library(caret)
library(C50)
library(e1071)
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
  # Decision Tree model
  tree_mod <- C5.0(x = train_data[, vars], y = factor(train_data[[target_var]]))
  plot(tree_mod)  # Plot decision tree
  
  # Predictions for decision tree
  predict_train_tree <- predict(tree_mod, newdata = train_data, type = "class")
  predict_test_tree <- predict(tree_mod, newdata = test_data, type = "class")
  
  strain <- table(train_data[[target_var]], predict_train_tree, dnn = c("Actual", "Predicted"))
  stest <- table(test_data[[target_var]], predict_test_tree, dnn = c("Actual", "Predicted"))
  
  accuracy_train_tree <- sum(diag(strain)) / sum(strain)
  sensitivity_train_tree <- strain[2, 2] / sum(strain[2, ])
  specificity_train_tree <- strain[1, 1] / sum(strain[1, ])
  
  accuracy_test_tree <- sum(diag(stest)) / sum(stest)
  sensitivity_test_tree <- stest[2, 2] / sum(stest[2, ])
  specificity_test_tree <- stest[1, 1] / sum(stest[1, ])
  
  # Naive Bayes model
  nb_mod <- naiveBayes(as.formula(paste(target_var, "~ .")), data = train_data)
  
  # Predictions for Naive Bayes
  predict_train_nb <- predict(nb_mod, newdata = train_data)
  predict_test_nb <- predict(nb_mod, newdata = test_data)
  
  strain_nb <- table(train_data[[target_var]], predict_train_nb, dnn = c("Actual", "Predicted"))
  stest_nb <- table(test_data[[target_var]], predict_test_nb, dnn = c("Actual", "Predicted"))
  
  accuracy_train_nb <- sum(diag(strain_nb)) / sum(strain_nb)
  sensitivity_train_nb <- strain_nb[2, 2] / sum(strain_nb[2, ])
  specificity_train_nb <- strain_nb[1, 1] / sum(strain_nb[1, ])
  
  accuracy_test_nb <- sum(diag(stest_nb)) / sum(stest_nb)
  sensitivity_test_nb <- stest_nb[2, 2] / sum(stest_nb[2, ])
  specificity_test_nb <- stest_nb[1, 1] / sum(stest_nb[1, ])
  
  list(
    decision_tree_train = data.frame(Accuracy = accuracy_train_tree, Sensitivity = sensitivity_train_tree, Specificity = specificity_train_tree),
    decision_tree_test = data.frame(Accuracy = accuracy_test_tree, Sensitivity = sensitivity_test_tree, Specificity = specificity_test_tree),
    naive_bayes_train = data.frame(Accuracy = accuracy_train_nb, Sensitivity = sensitivity_train_nb, Specificity = specificity_train_nb),
    naive_bayes_test = data.frame(Accuracy = accuracy_test_nb, Sensitivity = sensitivity_test_nb, Specificity = specificity_test_nb)
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
  
  train_results[[paste0(p * 100, "%")]] <- res
  test_results[[paste0(p * 100, "%")]] <- res
}

# Combining results for decision tree
train_results_df <- do.call(rbind, lapply(train_results, function(res) res$decision_tree_train))
test_results_df <- do.call(rbind, lapply(test_results, function(res) res$decision_tree_test))

# Combining results for Naive Bayes
train_results_nb_df <- do.call(rbind, lapply(train_results, function(res) res$naive_bayes_train))
test_results_nb_df <- do.call(rbind, lapply(test_results, function(res) res$naive_bayes_test))

# Adding partition labels to the data frames
train_results_df$Partition <- rownames(train_results_df)
test_results_df$Partition <- rownames(test_results_df)
train_results_nb_df$Partition <- rownames(train_results_nb_df)
test_results_nb_df$Partition <- rownames(test_results_nb_df)

# Display training and test set results for Decision Tree
cat("Training Set Results for Decision Tree:\n")
print(train_results_df)
cat("\nTest Set Results for Decision Tree:\n")
print(test_results_df)

# Display training and test set results for Naïve Bayes
cat("\nTraining Set Results for Naïve Bayes:\n")
print(train_results_nb_df)
cat("\nTest Set Results for Naïve Bayes:\n")
print(test_results_nb_df)