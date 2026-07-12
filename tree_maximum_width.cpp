class Solution {
  public:
    //int maxWidth(Node* root) {
        // code here
    //     if(root==nullptr) return 0;
    //     long long ans=0;
    //     queue<pair<Node*,int>> q;
    //     q.push({root,0});
    //     while(!q.empty()){
    //         int size=q.size();
    //         long long minIndex=q.front().second;
    //         long long first=0,last=0;
    //         for(int i=0;i<size;i++){
    //             auto front=q.front();         LEETCODE solution
    //             q.pop();
    //             Node* node=front.first;
    //             long long curr=front.second-minIndex;
    //             if(i==0) first=curr;
    //             if(i==size-1) last=curr;
    //             if(node->left) q.push({node->left,2*curr});
    //             if(node->right) q.push({node->right,2*curr+1});
    //         }
    //         ans=max(ans,last-first+1);
    //     }
    //     return (int)ans;
    // }
    int maxWidth(Node* root) {

        if (root == NULL)
            return 0;

        queue<Node*> q;
        q.push(root);

        int ans = 0;

        while (!q.empty()) {

            int size = q.size();

            ans = max(ans, size);

            while (size--) {

                Node* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};
