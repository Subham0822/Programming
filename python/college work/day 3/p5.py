def find_max_min(*args):
    if not args:
        return None, None
    else:
        max=args[0]
        min=args[0]
        for i in args:
            if max<i:
                max=i
            if min>i:
                min=i
        return max,min

numbers=[10,20,30,40,50]
max, min=find_max_min(*numbers)
print(max, min)