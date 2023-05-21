/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    if(typeof o1!=typeof o2)
    {
       return false;
    }
    if((o1==null||o2==null)||(typeof o1!='object'&&typeof o2!='object'))
    {
       return (o1===o2);
    }
    if(Object.keys(o1).length!=Object.keys(o2).length)  
    {
       return false;
    }
    if((o1 instanceof Array || o2 instanceof Array)&&!(o1 instanceof Array && o2 instanceof Array))
    {
          return false;
    }
    for(let prop in o1)
    {
        if(!o2.hasOwnProperty(prop))  
        {
            return false;
        }
        if(!areDeeplyEqual(o1[prop],o2[prop]))  
        {
            return false;
        }
    }
    return true;
};