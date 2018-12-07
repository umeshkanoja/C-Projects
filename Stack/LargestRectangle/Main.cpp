#include <bits/stdc++.h>
#include <stack>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    stack<int> data, index;
    long maxArea = 0, lastValidIndex=0;
    for (int i = 0; i < h.size(); i++){
        if ((data.empty() && h[i] > 0) || (!data.empty() && data.top() < h[i])){
            data.push(h[i]);
            index.push(i);
            lastValidIndex = i;
            continue;
        }

        if (!data.empty()) {
            long sum = 0, lastIndex=0;
            while(!data.empty() && data.top() >= h[i]){
                sum = data.top() * (i - index.top());
                if (sum > maxArea) {
                    maxArea = sum;
                }

                lastIndex = index.top();
                data.pop();
                index.pop();
            }

            if (h[i]>0){
                data.push(h[i]);
                index.push(lastIndex);
                lastValidIndex = i;
            }
        }
    }

    while (!data.empty()) {
        long sum = data.top() * (lastValidIndex - index.top() + 1);
        if (sum > maxArea) maxArea = sum;
        data.pop();
        index.pop();
    }

    return maxArea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

