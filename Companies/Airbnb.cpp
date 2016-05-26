// [median row] (coding + SQL)
// Given the following table
// id  value
// 0   1
// 1   2
// 0   4
// 1   0
// 1   5
// 0   10
// ...

// Find the row corresponding to the median time for each id
// id  value
// 0   4
// 1   2
// ...
// https://msdn.microsoft.com/en-us/library/ms186734.aspx

select id, Median=AVG(1.0 * N) from
(select id , row_num =ROW_NUMBER() from table order by value as t1,
(select count(*) as total_rows) 
from table where id = give_id as t2 ) AS y
where row_num IN ((total_rows+1)/2, (total_rows+2)/2) 
group by id;

/*
# Example Streaming data 
id  value
0   1
0   0
0   5
...
0   2
0   4
0   10

1   0
...
1   0
1   5
1   10
1   7
1   1
1   3

2   1
...
2   0
2   50
2   1
2   7
2   5
2   2
*/


#include <iostream>
using namespace std;

// To execute C++, please define "int main()"
void get_median(const set<int>& values) {
  int size = values.size();
  if(size == 0) return 0;
  
  int median =0;
  if(size %2 ==0) {
    median = (values[(size)/2] + values[(size+1)/2])/2;
  } else {
    median = values[size/2];
  }
  return median;
}
/*
0   4
0   10

1   0
...
1   0
1   5*/

int main() {
  int prev_id =0;
  pair<int,int> id_val_pair;
  set<int> values;
  cin >> id_val_pair.first;
  prev_id = id_val_pair.first;
  while(true) {
    if(prev_id == id_val_pair.first) {
      cin >> id_val_pair.second;
      values.insert(id_val_pair.second);
      cin >> id_val_pair.first;
    }
    else  {
      cout << get_median(values);
      values.clear();
      prev_id = id_val_pair.first;
    }
  }
  
  return 0;
}
