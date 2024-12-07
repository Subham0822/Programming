auto<-read.csv("C:\\Users\\RWIK\\Downloads\\auto-mpg.csv",header=TRUE)
pairs(~mpg +displacement, data=auto)
pairs(~mpg +displacement+horsepower, data=auto)
