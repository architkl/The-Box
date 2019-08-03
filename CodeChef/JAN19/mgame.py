def eval(n,i,j,k):
    return (((n%i)%j)%k)%n

b = True
# n==p SOLVED
# p > n max is (n-1)/2
for t in range(1,20):
    for t2 in range(1,20):
        #n , p = [int(ele) for ele in input().split()]
        n = t
        p = t2
        triplets = []
        Is = []
        Js = []
        Ks = []
        m = -1
        for i in range(1,p+1):
            for j in range(1,p+1):
                for k in range(1,p+1):
                    temp = eval(n,i,j,k)
                    if temp > m:
                        m = temp

        for i in range(1,p+1):
            for j in range(1,p+1):
                for k in range(1,p+1):
                    temp = eval(n,i,j,k)
                    if temp == m:
                        triplets.append((i,j,k))
                        Is.append(i)
                        Js.append(j)
                        Ks.append(k)

                    #print(triplets)
                #print("Case : "+str(n)+" "+str(p))
        #print("Triplet Length : "+str(len(triplets)))
        
        if m!=( ((n-1)//2) ) :
            print("Case : "+str(n)+" "+str(p))
            print("Max --> "+str(m))
                #Is = sorted(Is)
                #Js = sorted(Js)
                #Ks = sorted(Ks)
                #print(triplets)
                #print(Is)
                #print(Js)
                #print(Ks)
                    #count = 0
                    #for ele in Is:
                    #    if ele==Is[0]:
                    #        count+=1
                    #print(str(t)+" "+str(t2)+"-->"+str(count))
                #print("*********************************")
                    #if t2==1:
                    #    b = b and len(triplets)==1
print(b)