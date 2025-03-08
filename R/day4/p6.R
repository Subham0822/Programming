auto<-read.csv("C:\\Users\\RWIK\\Downloads\\auto-mpg.csv",header=TRUE)
barplot(auto$mpg, main = "MPG Plot", xlab = "mpg", col = "black", horiz = FALSE)
