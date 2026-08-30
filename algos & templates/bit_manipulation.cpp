if(x & 1)//check odd (if last bit is 1)
if(x & (1LL << i))//check if ith bit is set
x |= (1LL << i);//set ith bit
x &= ~(1LL << i);//unset ith bit
x ^= (1LL << i);//toggle ith bit
x & -x//get last set bit
x & (x - 1)//check if x is power of 2
x &= x - 1;//remove the last set bit
//count set bits
__builtin_popcount(x);
__builtin_popcountll(x);
//Enumerate Submasks
for(int sub = mask; sub; sub = (sub - 1) & mask) {

    // sub is a submask of mask
}
//including 0
for(int sub = mask;; sub = (sub - 1) & mask) {

    // use sub

    if(sub == 0)
        break;
}
