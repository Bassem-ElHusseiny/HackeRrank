function countPairs(arr) {
    let arrCount = [];
    let new_arr = [];
    arr.sort((a, b) => a - b);
    arrCount.push(1);
    new_arr.push(arr[0]);
    let count = 0;
    
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] == arr[i + 1]) {
            ++arrCount[count];
            continue
        }
        new_arr.push(arr[i + 1]);
        arrCount.push(1);
        count++;
    }

    let ans = 0;
    let andOp = 0
    for (let i = 0; i < arrCount.length; i++) {
        for (let j = i; j < arrCount.length; j++) {
            andOp = new_arr[i] & new_arr[j];
            if (andOp && (!(andOp & (andOp - 1)))) {
                if (new_arr[i] === new_arr[j]) {
                    ans += (arrCount[i] * (arrCount[i] - 1)) / 2;
                } else {
                    ans += arrCount[i] * arrCount[j];
                }
            }
        }
    }
    return ans;
}