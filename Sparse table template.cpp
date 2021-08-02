const ll mx =2e5 + 10, mxw = 18;
ll sparseTable[mx][mxw];

void build(vector<ll>&v1){

    FOR1(i,v1.size()-1 )sparseTable[i][0] = v1[i];

    for(int j=1;(1<<j)<v1.size(); j++ ){

        for(int i=1; i + (1<<j) <=v1.size();i++){

            int mid = j-1;
            sparseTable[i][j] =GCD(sparseTable[i][mid], sparseTable[i+ (1<<mid)  ][mid]);

            // [i][i+2^J) = GCD [i][i + 2^(J-1)] , GCD[i+2^J-1][2^j) )
        }
    }

}

ll query(int L,int R){

    int mid = (int)log2(R-L+1);
    return GCD(sparseTable[L][mid], sparseTable[R-(1<<mid) + 1][mid]  );
}
