# Load the dataset
d <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/ClassificationSimpleLab.csv")

# Display dataset
print(d)

# Table for 'buys_computer'
f <- table(d$buys_computer)
print("Table of buys_computer:")
print(f)

# Table for 'age' and 'buys_computer'
t <- table(d$age, d$buys_computer)
print("Table (age vs buys_computer):")
print(t)

# Proportions for age groups
prop1 <- t[1,] / sum(t[1,])
print("Proportions for first age group (youth):")
print(prop1)

prop2 <- t[2,] / sum(t[2,])
print("Proportions for second age group (middle-aged):")
print(prop2)

prop3 <- t[3,] / sum(t[3,])
print("Proportions for third age group (senior):")
print(prop3)

# Entropy calculations for age groups
H1 <- -(prop1[1] * log2(prop1[1])) - (prop1[2] * log2(prop1[2]))
H11 <- ifelse(is.na(H1), 0, H1)
print(paste("Entropy for age group 1 (youth):", H11))

H2 <- -(prop2[1] * log2(prop2[1])) - (prop2[2] * log2(prop2[2]))
H22 <- ifelse(is.na(H2), 0, H2)
print(paste("Entropy for age group 2 (middle-aged):", H22))

H3 <- -(prop3[1] * log2(prop3[1])) - (prop3[2] * log2(prop3[2]))
H33 <- ifelse(is.na(H3), 0, H3)
print(paste("Entropy for age group 3 (senior):", H33))

# Calculate xx
xx <- (table(d$age)[1] / length(d$age)) * H11 +
      (table(d$age)[2] / length(d$age)) * H22 +
      (table(d$age)[3] / length(d$age)) * H33
xx <- unname(ifelse(is.na(xx), 0, xx))
print(paste("Weighted entropy (xx):", xx))

# Overall entropy (r)
r <- -(f[1] / nrow(d)) * log2(f[1] / nrow(d)) - (f[2] / nrow(d)) * log2(f[2] / nrow(d))
r <- unname(r)
print(paste("Overall entropy (r):", r))

# Information gain (e)
e <- r - xx
print(paste("Information gain (e):", e))









# output

# # Load the dataset
# d <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/ClassificationSimpleLab.csv")
# > # Load the dataset
# > d <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/ClassificationSimpleLab.csv")
# > # Display dataset
# > print(d)
#    RID         age income student credit_rating buys_computer
# 1    1       youth   high      no          fair            no
# 2    2       youth   high      no     excellent            no
# 3    3 middle_aged   high      no          fair           yes
# 4    4      senior medium      no          fair            no
# 5    5      senior    low     yes          fair            no
# 6    6      senior    low     yes     excellent           yes
# 7    7 middle_aged    low     yes     excellent           yes
# 8    8       youth medium      no          fair            no
# 9    9       youth    low     yes          fair           yes
# 10  10      senior medium     yes          fair            no
# 11  11       youth medium     yes     excellent           yes
# 12  12 middle_aged medium      no     excellent           yes
# 13  13 middle_aged   high     yes          fair           yes
# 14  14      senior medium      no     excellent           yes
# > # Table for 'buys_computer'
# > f <- table(d$buys_computer)
# > print("Table of buys_computer:")
# [1] "Table of buys_computer:"
# > print(f)

#  no yes 
#   6   8 
# > # Table for 'age' and 'buys_computer'
# > t <- table(d$age, d$buys_computer)
# > print("Table (age vs buys_computer):")
# [1] "Table (age vs buys_computer):"
# > print(t)
             
#               no yes
#   middle_aged  0   4
#   senior       3   2
#   youth        3   2
# > # Proportions for age groups
# > prop1 <- t[1,] / sum(t[1,])
# > print("Proportions for first age group (youth):")
# [1] "Proportions for first age group (youth):"
# > print(prop1)
#  no yes 
#   0   1 
# > prop2 <- t[2,] / sum(t[2,])
# > print("Proportions for second age group (middle-aged):")
# [1] "Proportions for second age group (middle-aged):"
# > print(prop2)
#  no yes 
# 0.6 0.4 
# > prop3 <- t[3,] / sum(t[3,])
# > print("Proportions for third age group (senior):")
# [1] "Proportions for third age group (senior):"
# > print(prop3)
#  no yes 
# 0.6 0.4 
# > # Entropy calculations for age groups
# > H1 <- -(prop1[1] * log2(prop1[1])) - (prop1[2] * log2(prop1[2]))
# > H11 <- ifelse(is.na(H1), 0, H1)
# > print(paste("Entropy for age group 1 (youth):", H11))
# [1] "Entropy for age group 1 (youth): 0"
# > H2 <- -(prop2[1] * log2(prop2[1])) - (prop2[2] * log2(prop2[2]))
# > H22 <- ifelse(is.na(H2), 0, H2)
# > print(paste("Entropy for age group 2 (middle-aged):", H22))
# [1] "Entropy for age group 2 (middle-aged): 0.970950594454669"
# > H3 <- -(prop3[1] * log2(prop3[1])) - (prop3[2] * log2(prop3[2]))
# > H33 <- ifelse(is.na(H3), 0, H3)
# > print(paste("Entropy for age group 3 (senior):", H33))
# [1] "Entropy for age group 3 (senior): 0.970950594454669"
# > # Calculate xx
# > xx <- (table(d$age)[1] / length(d$age)) * H11 +
# +       (table(d$age)[2] / length(d$age)) * H22 +
# +       (table(d$age)[3] / length(d$age)) * H33
# xx <- unname(ifelse(is.na(xx), 0, xx))
# > xx <- unname(ifelse(is.na(xx), 0, xx))
# > print(paste("Weighted entropy (xx):", xx))
# [1] "Weighted entropy (xx): 0.693536138896192"
# > # Overall entropy (r)
# > r <- -(f[1] / nrow(d)) * log2(f[1] / nrow(d)) - (f[2] / nrow(d)) * log2(f[2] / nrow(d))
# > r <- unname(r)
# > print(paste("Overall entropy (r):", r))
# [1] "Overall entropy (r): 0.985228136034252"
# > # Information gain (e)
# > e <- r - xx
# > print(paste("Information gain (e):", e))
# [1] "Information gain (e): 0.29169199713806"