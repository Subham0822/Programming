file1 <- read.csv("C:\\Users\\RWIK\\Downloads\\Assocclass24.csv")
cat("No. of columns: ",ncol(file1))
cat("\nName of the columns: ",colnames(file1))
cat("\nNo. of rows: ",nrow(file1))
male=file1[which(file1$Sex=="M"),]
cat("\nNp. of Male Customers: ",nrow(male))
female=file1[which(file1$Sex=="F"),]
cat("\nNp. of Female Customers: ",nrow(female))
e=file1[which((file1$Age == "Middle")&(file1$Milk == 1)&(file1$Diaper==1)),]
cat("\nNo. of Middle Aged customers that buy milk and diaper: ",nrow(e))
f=file1[which((file1$Bread == 1)&(file1$Milk == 1)&(file1$Diaper==1)),]
percentage=(nrow(f)/nrow(file1))*100
cat("\nsupport = ",percentage)
