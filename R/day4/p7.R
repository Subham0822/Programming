auto<-read.csv("C:\\Users\\RWIK\\Downloads\\auto-mpg.csv",header=TRUE)
boxplot(auto$mpg, xlab = "Miles per gallon", col = "lightgray")
boxplot(mpg ~ cylinders, data=auto)
