/**
 * @param {string} word
 * @return {number}
 */
var numberOfSpecialChars = function(word) {
    const mp = new Map();
    for(const cr of word){
        if(cr === cr.toLowerCase()){
            mp.set(cr,0); 
        }
    }
    for(const cr of word){
        if(cr != cr.toLowerCase()){
            if(mp.has(cr.toLowerCase())){
                mp.set(cr.toLowerCase(),1)
            }
        }
    }
    const res = Array.from(mp.values()).filter(val => val === 1).length;
    return res;
};