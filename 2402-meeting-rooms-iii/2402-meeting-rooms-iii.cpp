class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meets) {
        int cnt[101] = {};
    sort(begin(meets), end(meets));
    priority_queue<int, vector<int>, greater<int>> avail;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
    for (int i = 0; i < n; ++i)
        avail.push(i);
    for (auto &m : meets) {
        while (!busy.empty() && busy.top().first <= m[0]) {
            avail.push(busy.top().second);
            busy.pop();
        }
        long long start = avail.empty() ? busy.top().first : m[0], duration = m[1] - m[0];
        int room = avail.empty() ? busy.top().second : avail.top();
        if (avail.empty())
            busy.pop();
        else
            avail.pop();
        ++cnt[room];
        busy.push({start + duration, room});
    }
    return max_element(begin(cnt), end(cnt)) - begin(cnt);
}
};