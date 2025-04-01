/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:11:19 by mekundur          #+#    #+#             */
/*   Updated: 2025/04/01 17:40:52 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str = "Hello Mertcan";
    cout<<str;
    reverse(str.begin(), str.end());
	cout<<"\n"<<str<<"\n";
    return 0;
