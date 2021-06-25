bool isValid(int  I , bool graph[101][101] , int colour , int v1[101] )
{
    for(int i=0;i<101;i++)
    {
        if( i != I && graph[i][I]  )
        {
            if( v1[i] == colour)return false;
        }
    }
    return true;
    
}

bool Can(bool graph[101][101] , int m ,int V , int v , int v1[101] )
{
    if(v == V)return true;
    
    for(int i=0;i<m;i++)
    {
        if( !isValid(v,graph,i,v1)  )continue;
        
        v1[v] = i;
        
        if( Can(graph,m,V,v+1,v1)  )return true;
        
        v1[v] = -1;
            
        
    }
    
    return false;
    
        
    
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int v1[101];
    for(int i=0;i<101;i++)v1[i] = -1;
    
    return Can(graph,m,V,0,v1);
    
}