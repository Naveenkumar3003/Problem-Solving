string maxXorValue(string x, int k) {
    string y(x.length(),'0');
    for(int i=0;i<x.length()&& k>0;i++){
        if(x[i]=='0'){
            y[i]='1';
            k--;
        }
    }
    return y;
}
