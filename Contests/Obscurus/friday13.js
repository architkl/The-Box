function processData(input) {
    let inp = input.split('\n');
    // for (let i in inp)
    //     console.log(i + '->' + inp[i]);
    
    let t = inp[0], i = 1;
    
    while (i <= t)
    {
        let arr = inp[i].split(' ');
        let d1 = arr[0], m1 = arr[1], y1 = arr[2], d2 = arr[3], m2 = arr[4], y2 = arr[5];
        // console.log(d1 + ' ' + m1 + ' ' + y1 + ' ' + d2 + ' ' + m2 + ' ' + y2);
        
        let count = 0;
        let now = new Date(y2, m2-1, d2, 0, 0 , 0, 0);
        for (var d = new Date(y1, m1-1, d1, 0, 0 , 0, 0); d <= now; d.setDate(d.getDate() + 1)) {
            if (d.getDay() == 5 && d.getDate() == 13)
            {
                count++;
                // console.log(d);
            }
        }

        console.log(count);
        i++;
    }
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});