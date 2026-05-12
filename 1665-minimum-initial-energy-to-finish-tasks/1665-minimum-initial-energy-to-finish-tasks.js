/**
 * @param {number[][]} tasks
 * @return {number}
 */
var minimumEffort = function(tasks) {

    tasks.sort((a, b) => (b[1] - b[0]) - (a[1] - a[0]));

    let answer = 0;
    let energy = 0;

    for (let [actual, minimum] of tasks) {

        if (energy < minimum) {

            let need = minimum - energy;

            answer += need;
            energy += need;
        }

        energy -= actual;
    }

    return answer;
};