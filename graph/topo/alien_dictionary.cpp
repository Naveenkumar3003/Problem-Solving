class Solution {
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> indegree(n, 0);
        queue<int> q;
        vector<int> list;

        // Compute indegrees
        for (int i = 0; i < n; i++) {
            for (int next : adj[i]) {
                indegree[next]++;
            }
        }

        // Add nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's Algorithm
        while (!q.empty()) {
            int top = q.front();
            q.pop();

            list.push_back(top);

            for (int next : adj[top]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return list;
    }

public:
    string findOrder(vector<string> &words) {

        int n = words.size();

        // Adjacency list
        vector<vector<int>> adj(26);

        // Store characters that actually exist
        vector<int> present(26, 0);

        for (string word : words) {
            for (char ch : word) {
                present[ch - 'a'] = 1;
            }
        }

        // Create graph
        for (int i = 0; i < n - 1; i++) {

            string word1 = words[i];
            string word2 = words[i + 1];

            int j = 0;

            // Find first different character
            while (j < word1.length() &&
                   j < word2.length() &&
                   word1[j] == word2[j]) {
                j++;
            }

            // Invalid prefix case
            // Example: "abcd" comes before "ab"
            if (j == word2.length() && j < word1.length()) {
                return "";
            }

            // If a different character exists
            if (j < word1.length() && j < word2.length()) {

                int u = word1[j] - 'a';
                int v = word2[j] - 'a';

                adj[u].push_back(v);
            }
        }

        // Topological sort
        vector<int> topo = topoSort(adj);

        // Count characters actually present
        int totalChars = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                totalChars++;
            }
        }

        // If cycle exists
        if (topo.size() < totalChars) {
            return "";
        }

        // Create answer
        string ans = "";

        for (int it : topo) {

            // Only include characters present in words
            if (present[it]) {
                ans += char(it + 'a');
            }
        }

        return ans;
    }
};
