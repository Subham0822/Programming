import operator
d={1:3,2:6,3:1,4:2}
print(d)
sorted_d=sorted(d.items(),key=operator.itemgetter(1),reverse=True)
print(sorted_d)
