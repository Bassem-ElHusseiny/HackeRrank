function possibleChanges(usernames) {
	let ans = [];
for(let i=0;i<usernames.length;i++){
	
	let check=usernames[i].split("").sort().join("");
	if(usernames[i]!==check){
		ans.push("YES");
	}else{
		ans.push("NO");
	}
}

	return ans;
}