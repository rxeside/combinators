const token = 'vk1.a.7SgNwStbScck4Bccsx1Smaz5xX66FJORBBSfFlk3qe6WkpJLgYGuczJk-rPKwi4OhjNj6H_TlThVGEPJhofJA67zU_orWjgRuqY7zyz5EEpbbiXA8AB6u3fhCc8BFJDHKjp31Zd-4rNmDXKyLg7m2dq5rWIjt0-jBUnWNaT9EBbZmCjosP8kTVvUnzwBDpUga1w3mVsgp_XXpPWPcQpQaw'


async function fetchUserGroups(userId: string, callback: (data: any) => void) {
    try {
        const response = await fetch(`https://api.vk.com/method/groups.get?user_id=${userId}&access_token=${token}&v=5.199`)
        const data = await response.json();
        if (data.response) {
            callback(data)
        }
    } catch (error) {
        console.error(error);
    }
}

async function fetchGroupUsers(groupId: string, callback: (data: any) => void) {
    try {
        const response = await fetch(`https://api.vk.com/method/groups.getMembers?group_id=${groupId}&access_token=${token}&v=5.199`)
        const data = await response.json();
        if (data.response) {
            callback(data)
        }
    } catch (error) {
        console.error(error);
    }
}

async function fetchGroupInfo(groupIds: [string], callback: (data: any) => void) {
    try {
        const response = await fetch(`https://api.vk.com/method/groups.getById?group_ids=${groupIds.join(',')}&access_token=${token}&v=5.199`)
        const data = await response.json();
        if (data.response) {
            callback(data)
        }
    } catch (error) {
        console.error(error);
    }
}

export {
    fetchUserGroups,
    fetchGroupUsers,
    fetchGroupInfo,
}