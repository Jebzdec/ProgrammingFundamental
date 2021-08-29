while(i>=0 and j>=0){
        k=t;
        k+=int(a[i]-'0')+int(b[j]-'0');
        t=k/10;
        k=k%10;
        s.push_back(k);
        i--;
        j--;
    }
    for(int j=i;j>=0;j--) k=int(a[i]-'0');