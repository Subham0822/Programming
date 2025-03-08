auto<-read.csv("C:\\Users\\RWIK\\Downloads\\auto-mpg.csv",header=TRUE)
table(auto$mpg)
hist(auto$mpg, main = "MPG Plot", xlab = "mpg", col = "cyan", horiz = FALSE)
