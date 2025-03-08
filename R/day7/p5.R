install.packages("caret")
library(caret)
install.packages("C50")
library(C50)
install.packages("modeldata")
library(modeldata)

d <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/ClassificationSimplecases.csv")

# Convert 'buys' to a factor, as C5.0 requires a factor outcome
d$buys <- as.factor(d$buys)

# Check the structure to verify the conversion
str(d)

# Select necessary columns for modeling
vars <- colnames(d)[2:5]

# Prepare the dataset with the selected columns
cc <- d[, c(vars, "buys")]

# Create training set (70%)
set.seed(1234)
sz <- nrow(cc) * 0.7
in_train <- sample(1:nrow(cc), size = sz)
train_data <- cc[in_train, ]
test_data <- cc[-in_train, ]

# Build the C5.0 decision tree model
tree_mod <- C5.0(x = train_data[, vars], y = train_data$buys)

# Make predictions for both training and test sets
predit_train <- predict(tree_mod, newdata = train_data, type = "class")
predit_test <- predict(tree_mod, newdata = test_data, type = "class")

# Confusion matrices for training and test sets
strain <- table(train_data$buys, predit_train, dnn = c("Actual", "Predicted"))
stest <- table(test_data$buys, predit_test, dnn = c("Actual", "Predicted"))

# Accuracy calculations for training and test sets
accuracytrain <- sum(diag(strain)) / sum(strain)
accuracytest <- sum(diag(stest)) / sum(stest)
print(paste("Training Accuracy: ", accuracytrain))
print(paste("Test Accuracy: ", accuracytest))

# Sensitivity and specificity for training and test sets
sensitivitytrain <- strain[2, 2] / sum(strain[2, ])
sensitivitytest <- stest[2, 2] / sum(stest[2, ])
print(paste("Training Sensitivity: ", sensitivitytrain))
print(paste("Test Sensitivity: ", sensitivitytest))

specftrain <- strain[1, 1] / sum(strain[1, ])
specftest <- stest[1, 1] / sum(stest[1, ])
print(paste("Training Specificity: ", specftrain))
print(paste("Test Specificity: ", specftest))

# Plot the decision tree
plot(tree_mod)