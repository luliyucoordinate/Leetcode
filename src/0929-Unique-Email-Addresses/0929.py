class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        raw_emails = set()
        for email in emails:
            sp_at = email.split('@')
            pre = sp_at[0].split('+')
            raw_emails.add(pre[0].replace('.', '') + sp_at[1])

        return len(raw_emails)
        

if __name__ == "__main__":
    emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
    print(Solution().numUniqueEmails(emails))