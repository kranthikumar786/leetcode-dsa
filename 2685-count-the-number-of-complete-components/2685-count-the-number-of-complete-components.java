class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        DisjointSet dj=new DisjointSet();
        for(int i=0;i<n;i++){
            dj.createSet(i);
        }
        for(int []e:edges){
            int u=e[0];
            int v=e[1];
            dj.union(u,v);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(dj.find(i)==i){
                int e=dj.getedge(i);
                int v=dj.getvertex(i);
               if (e == v * (v - 1) / 2)
               comp++;
            }
        }
        return comp;
    }
    public class DisjointSet{
        public class Node{
            int val;
            int rank;
            int vertex;
            int edge;
            Node parent;

        }
        HashMap<Integer,Node>map=new HashMap<>();
        public void createSet(int v){
          Node nn=new Node();
          nn.val=v;
          nn.rank=1;
          nn.vertex=1;
          nn.edge=0;
          nn.parent=nn;
          map.put(v,nn);
        }
        public int find(int v){
            Node nn=map.get(v);
            return find(nn).val;
        }
        public Node find(Node nn){
            if(nn==nn.parent){
                return nn;
            }
            Node rn=find(nn.parent);
            nn.parent=rn;
            return rn;
        }
        public void union(int v1,int v2){
            Node n1=map.get(v1);
            Node n2=map.get(v2);
            Node rn1=find(n1);
            Node rn2=find(n2);
            if(rn1==rn2){
                rn1.edge++;
                return;
            }
            if(rn1.rank>rn2.rank){
                rn2.parent=rn1;
               
                rn1.edge+=rn2.edge+1;
                rn1.vertex+=rn2.vertex;
            }
            else if(rn2.rank>rn1.rank){
                rn1.parent=rn2;
                rn2.edge+=rn1.edge+1;
                rn2.vertex+=rn1.vertex;
                
            }
            else{
                rn2.parent=rn1;
                rn1.rank++;
                rn1.edge+=rn2.edge+1;
                rn1.vertex+=rn2.vertex;
            }
        }
            public int getedge(int v){
                Node rn=map.get(v);
                return find(rn).edge;
            }
            public int getvertex(int v){
                Node rn=map.get(v);
                return find(rn).vertex;
            }
        }
}