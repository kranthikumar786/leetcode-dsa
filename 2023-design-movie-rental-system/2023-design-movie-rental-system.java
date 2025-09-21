class MovieRentingSystem {
 
   private static class MovieEntry {
       final int shopId;
       final int movieId;
       final int price;
       MovieEntry(int shopId,int movieId, int price) {
          this.shopId = shopId;
          this.movieId = movieId;
          this.price = price;
       }
   }
    private static final Comparator<MovieEntry>CMP = (a,b)-> {
       Integer c = Integer.compare(a.price,b.price);
        if(c != 0)  return c;
        c = Integer.compare(a.shopId,b.shopId);
        if(c != 0) return c;
        return Integer.compare(a.movieId,b.movieId);  
    };
   private final HashMap<Integer,TreeSet<MovieEntry>>availableByMovie = new HashMap<>();
   private final TreeSet<MovieEntry>rentedSet = new TreeSet<>(CMP);
   private final HashMap<Long,MovieEntry>byPair = new HashMap<>();
//    private static long key(int shop, int movie) {
//         return (((long) shop) << 32) ^ (movie & 0xffffffffL);
//     }
private static long key(int shop, int movie) {
    return (((long) shop) << 32) | (movie & 0xffffffffL);
}

    public MovieRentingSystem(int n, int[][] entries) {
      for(int [] e : entries) {
          int shopId = e[0] ;int movieId = e[1]; int price = e[2];
          MovieEntry movieEntry = new MovieEntry(shopId,movieId,price);
          byPair.put(key(shopId,movieId),movieEntry);
          availableByMovie
                .computeIfAbsent(movieId, k -> new TreeSet<>(CMP))
                .add(movieEntry);
      }
    }
    public List<Integer> search(int movie) {
        List<Integer>ans = new ArrayList<>();
        TreeSet<MovieEntry>set = availableByMovie.get(movie);
        if(set == null || set.isEmpty()) {return ans;}
        Iterator<MovieEntry> itr = set.iterator();
        for(int i = 0 ; i < 5 && itr.hasNext() ; i++) {
              ans.add(itr.next().shopId);
        }
        return ans;
    }
    public void rent(int shop, int movie) {
        long k = key(shop,movie);
        MovieEntry movieEntry = byPair.get(k);
        if(movieEntry == null){
              return;
        }
         TreeSet<MovieEntry> set = availableByMovie.get(movie);
         if(set != null) {
            set.remove(movieEntry);
         }
         rentedSet.add(movieEntry); 
    }
    public void drop(int shop, int movie) {
        long k = key(shop,movie);
        MovieEntry movieEntry = byPair.get(k);
        if(movieEntry == null) return ;
         rentedSet.remove(movieEntry);
        availableByMovie
         .computeIfAbsent(movie, x-> new TreeSet<>(CMP)) 
         .add(movieEntry);
    }
    public List<List<Integer>> report() {
       List<List<Integer>>ans = new ArrayList<>(5);
       Iterator<MovieEntry>itr = rentedSet.iterator();
        for(int i = 0 ;i < 5 && itr.hasNext(); i++) {
            MovieEntry movieEntry = itr.next();
            ans.add(Arrays.asList(movieEntry.shopId,movieEntry.movieId));
        }
       return ans;   
    }
}
/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem obj = new MovieRentingSystem(n, entries);
 * List<Integer> param_1 = obj.search(movie);
 * obj.rent(shop,movie);
 * obj.drop(shop,movie);
 * List<List<Integer>> param_4 = obj.report();
 */