# General function for xx, r, and e computation for any variable
Compute <- function(x, y) {
  t <- table(x, y)
  
  # Calculate proportions and entropy for each group
  prop_entropy <- function(i) {
    prop <- t[i, ] / sum(t[i, ])
    -(prop[1] * log2(prop[1])) - (prop[2] * log2(prop[2]))
  }
  
  # Calculate entropy for each group of x
  entropies <- sapply(1:nrow(t), prop_entropy)
  
  # Replace NA with 0
  entropies[is.na(entropies)] <- 0
  
  # Calculate weighted entropy (xx)
  xx <- sum((table(x) / length(x)) * entropies)
  
  # Calculate overall entropy (r)
  f <- table(y)
  r <- -(f[1] / length(y)) * log2(f[1] / length(y)) - (f[2] / length(y)) * log2(f[2] / length(y))
  
  # Information gain (e)
  e <- r - xx
  
  # Print values
  cat("Weighted entropy (xx):", xx, "\n")
  cat("Overall entropy (r):", r, "\n")
  cat("Information gain (e):", e, "\n")
  
  return(list(xx = xx, r = r, e = e))
}

# Example usage: Calculate for 'income' and 'buys_computer'
Compute(d$income, d$buys_computer)


# output
# # General function for xx, r, and e computation for any variable
# > Compute <- function(x, y) {
# +   t <- table(x, y)
# +   
# +   # Calculate proportions and entropy for each group
# +   prop_entropy <- function(i) {
# +     prop <- t[i, ] / sum(t[i, ])
# +     -(prop[1] * log2(prop[1])) - (prop[2] * log2(prop[2]))
# +   }
# +   
# +   # Calculate entropy for each group of x
# +   entropies <- sapply(1:nrow(t), prop_entropy)
# +   
# +   # Replace NA with 0
# +   entropies[is.na(entropies)] <- 0
# +   
# +   # Calculate weighted entropy (xx)
# +   xx <- sum((table(x) / length(x)) * entropies)
# +   
# +   # Calculate overall entropy (r)
# +   f <- table(y)
# +   r <- -(f[1] / length(y)) * log2(f[1] / length(y)) - (f[2] / length(y)) * log2(f[2] / length(y))
# +   
# +   # Information gain (e)
# +   e <- r - xx
# +   
# +   # Print values
# +   cat("Weighted entropy (xx):", xx, "\n")
# +   cat("Overall entropy (r):", r, "\n")
# +   cat("Information gain (e):", e, "\n")
# +   
# +   return(list(xx = xx, r = r, e = e))
# + }
# > # Example usage: Calculate for 'income' and 'buys_computer'
# > Compute(d$income, d$buys_computer)
# Weighted entropy (xx): 0.9460795 
# Overall entropy (r): 0.9852281 
# Information gain (e): 0.03914867 
# $xx
# [1] 0.9460795

# $r
#        no 
# 0.9852281 

# $e
#         no 
# 0.03914867 
