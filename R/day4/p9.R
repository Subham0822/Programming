auto<-read.csv("C:\\Users\\RWIK\\Downloads\\auto-mpg.csv",header=TRUE)
cyl<-table(auto$cylinders)
print(cyl)
barplot(cyl, main="Barplot of cylinders", xlab="cylinders", ylab="frequency")
