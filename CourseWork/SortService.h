#pragma once
#include "Account.h"
#include <algorithm>
#include "ViewService.h"
class SortService
{
public:
	void SortAccountsDescending()
	{
		vector<Account> accounts = Storage::accounts;

		sort(accounts.begin(), accounts.end(), [](Account a, Account b)
			{
				return a.GetDate().GetConvDate() < b.GetDate().GetConvDate();
			});

		ViewService view;
		view.ShowAccounts(accounts);
	}

	void  SortAccountsAscending()
	{
		vector<Account> accounts = Storage::accounts;

		sort(accounts.begin(), accounts.end(), [](Account a, Account b)
			{
				return a.GetDate().GetConvDate() > b.GetDate().GetConvDate();
			});

		ViewService view;
		view.ShowAccounts(accounts);
	}
};

