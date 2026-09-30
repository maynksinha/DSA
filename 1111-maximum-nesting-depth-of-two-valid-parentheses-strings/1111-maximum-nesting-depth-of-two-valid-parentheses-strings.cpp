class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int count = 0; // Initialize the depth counter.
        vector<int> aux; // Initialize a vector to store the group assignment.

        // Iterate through each character in the string.
        for (auto i : seq) {
            if (i == '(') { // If it's an opening parenthesis:
                count++; // Increment the depth level.
            }
            aux.push_back(count % 2); // Assign the current parenthesis to a group based on the current depth level.
            if (i == ')') { // If it's a closing parenthesis:
                count--; // Decrement the depth level.
            }
        }
        return aux; // Return the vector containing the group assignments.
    }
};