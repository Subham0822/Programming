entropy <- function (x,y) {
  t<-table(x, y)
  H<-0
  for (i in 1:nrow(t))
  { prop<-t[i,]/sum(t[i,])
  Htmp <- -(prop[1]*log2(prop[1]))-(prop[2]*log2(prop[2]))
  HH<-ifelse(is.na(Htmp),0,Htmp)
  H<-H+(table(x)[i]/length(x))*HH
  }
  return(H)
}
gain <- function(x,y) {
  e <- entropy(x,y)
  f <- table(y)
  nr<-f[1]+f[2]
  r <- -(f[1]/nr)*log2(f[1]/nr)-(f[2]/nr)*log2(f[2]/nr)
  eage<- r -e
  v = c(e,eage)
  return(v)
}
#Main Code below
{
  d <- read.csv("/Users/sabyasachiganguli/Desktop/code/college codes/3rd sem/R/lab assignment/pdf/ClassificationSimpleLab 2.csv")
  dd = d
  m=-Inf
  ii=-1
  for(i in 2:(ncol(d)-1))
  {
    dc = d[,i]
    dclass = d[,ncol(d)]
    print(colnames(d[i]))
    v <- gain(dc, dclass)
    if(v[2] > m)
    { m=v[2]
    ii=i
    }
    print(paste("Entropy = ", unname(v[1]), "Gain =", unname(v[2])))
    2
  }
  print(paste("Maximum gain = ", m , " for attribute = ", colnames(d[ii])))
}

