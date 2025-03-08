file<-read.csv("C:\\Users\\RWIK\\Downloads\\GrocBinary24.csv",header=TRUE)
file1<-file[ ,2:6]
file1r<-data.frame(file1==1)
brules<-apriori(file1r, parameter=list(support=0.3, confidence=0.0, target="frequent itemsets"))
brules1<-apriori(file1r, parameter=list(support=0.4, confidence=0.6, target="rules"))
brules2<-apriori(file1r, parameter=list(support=0.3, confidence=0.7, target="rules"))
brules3<-apriori(file1r, parameter=list(support=0.4, confidence=0.4, target="rules"))

x=inspect(brules)
y=inspect(brules1)
z=inspect(brules2)
a=inspect(brules3)

final1<-x[ ,1]
final1

final2<-y[ ,1:3]
final2

final3<-z[which(z$lift>1),]
final3

final4<-a[which(a$confidence<=0.6),]
final4