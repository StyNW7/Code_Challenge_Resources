// Link: https://coddy.tech/challenges/doggy_love_js?daily=true

function dogLove(dogMessages, name) {

    return dogMessages.map(message => {
        if (message.includes(name)) {
            return message.replace(name, "WOOF");
        }
        return message;
    });

}
