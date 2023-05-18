var TimeLimitedCache = function() {
    this.cache = {};
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
  if (this.cache[key] && this.cache[key].timer) {
    clearTimeout(this.cache[key].timer);
    this.cache[key].value = value;
    this.cache[key].timer = setTimeout(() => {
      this.remove(key);
    }, duration);
    return true;
  } else {
    this.cache[key] = {
      value: value,
      timer: setTimeout(() => {
        this.remove(key);
      }, duration)
    };
    return false;
  }
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
  if (this.cache[key] && this.cache[key].timer) {
    return this.cache[key].value;
  } else {
    return -1;
  }
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
  let count = 0;
  for (const key in this.cache) {
    if (this.cache[key].timer) {
      count++;
    }
  }
  return count;
};

TimeLimitedCache.prototype.remove = function(key) {
  delete this.cache[key];
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */