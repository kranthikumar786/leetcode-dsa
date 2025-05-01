class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 1, right = min((int)tasks.size(), (int)workers.size()), maxAssignable = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssignTasks(mid, tasks, workers, pills, strength)) {
                maxAssignable = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return maxAssignable;
    }

private:
    bool canAssignTasks(int taskCount, const vector<int>& tasks, const vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers;

        for (int i = (int)workers.size() - taskCount; i < (int)workers.size(); ++i) {
            availableWorkers.insert(workers[i]);
        }

        for (int i = taskCount - 1; i >= 0; --i) {
            int requiredStrength = tasks[i];
            auto strongestWorkerIt = prev(availableWorkers.end());
            if (*strongestWorkerIt >= requiredStrength) {
                availableWorkers.erase(strongestWorkerIt);
            } else {
                if (pills == 0) {
                    return false;
                }
                auto workerIt = availableWorkers.lower_bound(requiredStrength - strength);
                if (workerIt == availableWorkers.end()) {
                    return false;
                }
                --pills;
                availableWorkers.erase(workerIt);
            }
        }

        return true;
    }
};





// class Solution {
// public:
//     int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
//       int n = tasks.size();
//       int m = workers.size();
//      sort(tasks.begin(),tasks.end());
//      sort(workers.begin(),workers.end());
//      int total = 0;
//     //    1 2 3   0 2 3 4 
//      int right = m-1;
//      for(int i = 0 ; i < n ;i++) {
//            for(int j = 0; j < m ;j++) {
//                 if(workers[j] != -1 && (workers[j] >= tasks[i]) || worrightkers[] >= tasks[i] ) {
//                       total++;
//                       workers[j] = -1;
//                        break;
//                 } else if((pills > 0) && (workers[j] != -1) && (long)(strength + workers[j]) >= (long) tasks[i]) {
//                        total++;
//                        workers[j] = -1; 
//                       pills--;
//                       break;
//                 } 
//            }
//      }
//      return total;
//     }
// };

/*
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

    int n = tasks.size();
     int total = 0;
     for(int i = 0 ;i < n ;i++) {
          for(int j = 0 ;  j < n ;j++) {
              if(workers[j] >= tasks[i]) {
                    total++;
                    workers[j] = -1;
                    break;  
                } else if((pills > 0) && (workers[j] != -1) && (long)(strength + workers[j]) >= (long) tasks[i]) {
                       total++;
                       workers[j] = -1; 
                      pills--;
                      break;
                }
          }
     }
     return total;
    }
};


 
  sum of task  =<  (sum of worker + piles * strenth)

     then it would works : 
     since it was not metioned  assigne the left most  closed max elemtn etc..

 catch here is : 
   taks and wokrers ar enot in same length : 


 also no containt by saying u have to use same  nof task == same no of workers : 
    but 


sum of task  =<  (sum of worker + piles * strenth)
  this won't work : 


  Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10

    tassks = 55 <= (40 + 30) but still not possble to complete the  all tasksL 
    so sum of task and sum of works + super power won't wroks: 



let's use this 
     since it was not metioned  assigne the left most  closed max elemtn etc..

     and sort the inputs: 
     abnd assinn smallest task to smallest worker : 

   tasks = [10,15,30], 
        
    workers = [0,10,10,10,10], 
       
       10  -  0 
       10  - 10 
    pills = 2, strength = 10
     taskscompplted = 1;

     15 - 10 : 
     15 - 20
      pills = 1, strength = 10
     taskscompplted = 2;

=======================
  


  30  10 : 
  30  10 + 10  (here should not muply with pille * strengt becuase one for one only) 
  
  30 20 
  still less : 
  
  pills = 0, strength = 10

here i can break this: 
  and return becuase 
   already sorted and in taks also iam going to have heavy : and next elemt in workers strenght
    also not going to satify contion : 

       pills = 3, strength = 10
Output: 2



  



t [5,4,3]
w [0,0,3]
p = 2: 
s = 5 

output : 3

t [5,4,3]
w [0,0,3]
p = 2: 
s = 5 

output :2



*/