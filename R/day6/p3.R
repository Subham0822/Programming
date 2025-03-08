# Function to compute Gini Index for a given proportion
gini <- function(prob) {
  1 - sum(prob^2)
}

# Generalized function for Gini index
ComputeGini <- function(x, y) {
  t <- table(x, y)
  
  # Calculate Gini index for each group of x
  prop_gini <- function(i) {
    prop <- t[i,] / sum(t[i,])
    gini(prop)
  }
  
  # Calculate Gini index for each group of x
  gini_values <- sapply(1:nrow(t), prop_gini)
  
  # Calculate weighted Gini index (xx)
  xx <- sum((table(x) / length(x)) * gini_values)
  
  # Calculate overall Gini index (r)
  f <- table(y)
  r <- gini(f / length(y))
  
  # Gini difference (e)
  e <- r - xx
  
  # Print values
  cat("Weighted Gini Index (xx):", xx, "\n")
  cat("Overall Gini Index (r):", r, "\n")
  cat("Gini Difference (e):", e, "\n")
  
  return(list(xx = xx, r = r, e = e))
}

# Example usage: Calculate Gini index for 'income' and 'buys_computer'
ComputeGini(d$income, d$buys_computer)


# output

# > # Function to compute Gini Index for a given proportion
# > gini <- function(prob) {
# +   1 - sum(prob^2)
# + }
# > # Generalized function for Gini index
# > ComputeGini <- function(x, y) {
# +   t <- table(x, y)
# +   
# +   # Calculate Gini index for each group of x
# +   prop_gini <- function(i) {
# +     prop <- t[i,] / sum(t[i,])
# +     gini(prop)
# +   }
# +   
# +   # Calculate Gini index for each group of x
# +   gini_values <- sapply(1:nrow(t), prop_gini)
# +   
# +   # Calculate weighted Gini index (xx)
# +   xx <- sum((table(x) / length(x)) * gini_values)
# +   
# +   # Calculate overall Gini index (r)
# +   f <- table(y)
# +   r <- gini(f / length(y))
# +   
# +   # Gini difference (e)
# +   e <- r - xx
# +   
# +   # Print values
# +   cat("Weighted Gini Index (xx):", xx, "\n")
# +   cat("Overall Gini Index (r):", r, "\n")
# +   cat("Gini Difference (e):", e, "\n")
# +   
# +   return(list(xx = xx, r = r, e = e))
# + }
# > # Example usage: Calculate Gini index for 'income' and 'buys_computer'
# > ComputeGini(d$income, d$buys_computer)
# Weighted Gini Index (xx): 0.4642857 
# Overall Gini Index (r): 0.4897959 
# Gini Difference (e): 0.0255102 
# $xx
# [1] 0.4642857

# $r
# [1] 0.4897959

# $e
# [1] 0.0255102

# > 