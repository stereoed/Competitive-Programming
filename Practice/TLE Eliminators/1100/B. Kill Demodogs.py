t = int(input())

MOD = 1000000007
for i in range(t):
    n = int(input())
    
    ans = (n * n) % MOD
    ans = ans + (n * (n - 1) // 2) % MOD
    sq = ((n * (n - 1)) * (2 * n - 1) // 3) % MOD
    ans = (ans + sq) % MOD
    ans = ans * 2022 % MOD
    print(int(ans))