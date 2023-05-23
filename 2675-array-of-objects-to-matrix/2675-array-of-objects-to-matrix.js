/**
 * @param {Array} arr
 * @return {Matrix}
 */
function flattenObj(obj, parent, res = {}){
    for(let key in obj){
        let propName = parent ? parent + '.' + key : key;
        if(typeof obj[key] == 'object' && obj[key] != null){
            flattenObj(obj[key], propName, res);
        } else {
            res[propName] = obj[key];
        }
    }
    return res;
}

var jsonToMatrix = function(arr) {
    let keys = [];
    let flat = arr.map((item) => flattenObj(item))

    for(let item of flat) {
        for(let key of Object.keys(item)) {
            if(!keys.includes(key)) {
                keys.push(key);
            }
        }
    }
    
    keys.sort();
    
    let res = [keys];
    for(let item of flat) {
        let row = [];
        for(let key of keys) {
            if(key in item) {
                row.push(item[key]);    
            } else {
                row.push("");
            }
        }
        res.push(row);
    }
    return res;
};