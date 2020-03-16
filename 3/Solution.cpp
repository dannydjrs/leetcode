class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i;
        int size = s.length();
        int max_length = 0, curr_length = 0;

        // Already seen chars + Set as not visited yet
        // 127 to hold all possible chars (see https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html)
        int* visited = new int[sizeof(int) * 127];
        for (i = 0; i < 256; i++) {
            visited[i] = -1;
        }

        for (int i = 0; i < size; i++) {
            // Previous index we saw this char
            int prev_index = visited[s[i]];

            // If we haven't visited this char before or we are counting
            // from further on from when last seen
            if (prev_index == -1 || i - curr_length > prev_index) {
                curr_length++;
            // Set the current length like we were counting from 1
            // after the last time we saw this char
            } else {
                curr_length = i - prev_index;
            }

            if (curr_length > max_length) {
                max_length = curr_length;
            }
            // Set that we have seen this char at this index
            visited[s[i]] = i;
        }

        return max_length;
    }
};
