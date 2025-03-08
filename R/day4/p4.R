auto<-read.csv("C:\\Users\\RWIK\\Downloads\\auto-mpg.csv",header=TRUE)
table(auto$acceleration)
hist(auto$acceleration, main = "Acceleration Plot", xlab = "Acceleration", col = "darkred", horiz = FALSE)
