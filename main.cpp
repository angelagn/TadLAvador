int main(){
    int cont=0;
    for(int i=1;i<4;i++){
        for(int j=3; j>=0; j--){
            cont =(i+j)%4;
            if((cont%(j+1))==1)
            {
                continue;
            }
        }
        if ((cont%4)==1)
        {
            continue;
        }
    }
}