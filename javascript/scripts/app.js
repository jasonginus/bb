// alert("connect")
// try {
//     let a = {
//         pxnum: undefined,
//         order_num: -1
//     };
//     console.log(Object.getOwnPropertyNames(a))
//     // let b = null;
//     console.log(1 + undefined)
//     console.log(("haha " + undefined) === "haha undefined")
//     console.log(b);
// }
// catch (ex) {
//     // console.log(Object.keys(ex));
//     console.log(JSON.stringify(JSON.stringify(ex, Object.getOwnPropertyNames(ex))));
// }
foo2("this", "is", "Quan")

function foo() {
    let msgArr = []
    for (let i=0; i<arguments.length; i++) {
        if (arguments[i] !== undefined) {
            msgArr.push(arguments[i])
        }
    }
    console.log(msgArr.join(" "))
    // console.log(msg)
}

function foo2(v1, v2) {
    console.log(v2)
}