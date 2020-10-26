#include <iostream>

using namespace std;

bool check_prime(int p)
{
  if (p <= 1) {
    return false;
  }
  if (p == 2){
    return true;
  }
  if (p%2 == 0){
    return false;
  }
  for (int i = (p-1); i > 1; i--){
    if (p%i == 0){
      return false;
    }
  }
  return true; 
}

main()
{
    int n;
    int count = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        if((n%i == 0) && (check_prime(i)))
        {
            count++;
        }
    }

    cout << count << endl;
}