/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
         var y=("Hello World");
       return y
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */