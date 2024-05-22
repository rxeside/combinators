import { findMostPopular } from './utils/findMostPopular';

async function main() {
    const groupId = '210114453';  // Замените на ID вашей группы
    const mostPopularUser = await findMostPopular(groupId);

    if (mostPopularUser) {
        console.log(`Самый популярный пользователь: ID = ${mostPopularUser.id}, Количество друзей = ${mostPopularUser.count}`);
    } else {
        console.log('Не удалось найти самого популярного пользователя.');
    }
}

main();
