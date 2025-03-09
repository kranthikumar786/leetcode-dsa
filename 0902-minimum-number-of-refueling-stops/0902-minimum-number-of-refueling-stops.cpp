class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> carStationWithFuel;
        int minNumber = 0, i = 0, n = stations.size();
        
        while (startFuel < target) {
            while (i < n && stations[i][0] <= startFuel) {
                carStationWithFuel.push(stations[i][1]);
                i++;
            }
            
            if (carStationWithFuel.empty()) {
                return -1;
            }
            
            startFuel += carStationWithFuel.top();
            carStationWithFuel.pop();
            minNumber++;
        }
        
        return minNumber;
    }
};

// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>carStationWithfuel;
//    for(auto station : stations){
//    carStationWithfuel.push({stations[0],stations[0]});
//    }
//    int minNumber = 0 ;
   
//    if(startFuel == target){return 0;}   
//     while(!carStationWithfuel.empty()){
//         auto currentCarStationWithfuel = carStationWithfuel.top();
//              carStationWithfuel.pop();
//          if(startFuel <= target){
//             return minNumber;
//          }
//          if(startFuel - currentCarStationWithfuel[0] < 0){
//             return -1;
//          }    
//         if(currentCarStationWithfuel[1] > startFuel - currentCarStationWithfuel[0]){
//              carStationWithfuel.push({currentCarStationWithfuel[0],currentCarStationWithfuel[1]}); 
//                 startFuel = currentCarStationWithfuel[1];    
//            minNumber++;
//         }else{
//            carStationWithfuel.push({currentCarStationWithfuel[0],startFuel});
//             minNumber++;
//         }
//     }
//    return  minNumber == 0  ? -1 : minNumber;

     /*
       can same dtatination can have differnt values ...? 
       ex : 
       target = 100, startFuel = 10, stations = [[10,60],[20,30],[20,70],[60,40]]
     
        ...? 
      final fuel can have more then target reaches as well..?  yes :
     it may stop  and refual ...?    refual means : remvoing previous less value : and loading current value into car : 
     
        while loading  :  
     does  value always sorted in terms of stations and fuel ...? to pick the next helping fule to reach destination ..? 
              
             stations can be ....? sorted based on dtiasnce ...? 
           ex 3: 
               target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
           
               10  =>  [10 ,60]  = > {}:

               10 ,  cloase value to satrfuel : 
                           so here  currentCarfuel < currentStaionFuel 

                                      pop element then pushnew values with pair<lastFuelPoint, currentCarFuel> :
        1 st check :  for(int i = 0 ; i<  n;i++) {
        }
     */   
//     }
// };