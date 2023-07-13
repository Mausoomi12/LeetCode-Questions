class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

       unordered_map<int,vector<int>>mpp;//to store cources which require a particular prerequisite
       unordered_map<int,int>ind; //to hash courses
       vector<int>ans;
       queue<int>q; //for BFS

       int n = prerequisites.size();

       for(int i = 0;i<n;++i)
       {
          mpp[prerequisites[i][1]].push_back(prerequisites[i][0]);
          ind[prerequisites[i][0]]++; //Cources to be Learned
       }
    
       for(int i = 0; i < numCourses; ++i)
       {
           if(!ind.count(i)) //Couses we have already learned 
           {
              q.push(i);
              ans.push_back(i);
           }
       }

       while(!q.empty())
       {
           auto t = q.front();
           q.pop();
           for(auto &it : mpp[t])
           {
               ind[it]--; 
               if(ind[it] == 0) //this course has been learned, as we had all the prerequisites for it
               {
                   ans.push_back(it); 
                   q.push(it); // it can now be used to unlock furthur courses
               }
           }
       }

      if(ans.size() != numCourses) return false; // if not all the courses are completed we return false
  
      return true;
    }
};