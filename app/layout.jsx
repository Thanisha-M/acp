import "./globals.css";

export const metadata = {
  metadataBase: new URL("https://thanisha-portfolio.vercel.app"),
  title: {
    default: "Thanisha M | AI & ML Engineer",
    template: "%s | Thanisha M"
  },
  description:
    "Personal portfolio of Thanisha M, an AI & ML Engineering student at REVA University building practical, human-centered AI applications.",
  keywords: [
    "Thanisha M",
    "AI ML engineer",
    "REVA University",
    "computer vision",
    "Python developer",
    "portfolio"
  ],
  authors: [{ name: "Thanisha M" }],
  creator: "Thanisha M",
  openGraph: {
    title: "Thanisha M | AI & ML Engineer",
    description:
      "AI & ML Engineering student, innovator, and problem solver building practical AI-powered applications.",
    url: "https://thanisha-portfolio.vercel.app",
    siteName: "Thanisha M Portfolio",
    type: "website",
    images: [
      {
        url: "/og-image.svg",
        width: 1200,
        height: 630,
        alt: "Thanisha M portfolio preview"
      }
    ]
  },
  twitter: {
    card: "summary_large_image",
    title: "Thanisha M | AI & ML Engineer",
    description:
      "AI & ML Engineering student at REVA University building useful, creative AI applications.",
    images: ["/og-image.svg"]
  },
  robots: {
    index: true,
    follow: true
  }
};

export default function RootLayout({ children }) {
  return (
    <html lang="en">
      <body>{children}</body>
    </html>
  );
}
